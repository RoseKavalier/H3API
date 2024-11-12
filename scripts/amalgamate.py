import os, re, time
from pathlib import Path
from datetime import datetime


g_root    = Path(__file__).parent.parent.resolve()
g_include = str(g_root / 'include').replace('\\','/') + '/'
g_h3api   = g_root  / 'include/h3api'


def is_include(line: str) -> bool:
    """
    Detects #include "h3api/XYZ" includes.
    """
    return line.strip().startswith('#include "')    


def find_includes(filepath: str) -> list[str]:
    """
    Find all dependencies of a header file.
    """
    headers = []
    lines = open(filepath, 'r', encoding='utf8').readlines()
    for line in lines:
        line = line.strip()
        if is_include(line):
            headers.append(line[line.find('"')+1 : line.rfind('"')])
    return headers


def collect_files(h3api_dir: str):
    """
    Grab all .hpp and .cpp files.
    """
    headers = []
    sources = []
    for root, _, files in os.walk(h3api_dir):
        for file in files:
            if file.endswith('.hpp'):
                headers.append(os.path.join(root, file).replace('\\','/'))
            elif file.endswith('.cpp'):
                sources.append(os.path.join(root, file).replace('\\','/'))

    return headers, sources


def can_be_written(dependencies, written_headers):
    """
    A header file can be written if it has 0 dependencies or if all
    of its dependencies are already written.
    """
    if len(dependencies) == 0:
        return True
    for dep in dependencies:
        if dep not in written_headers:
            return False
    return True


def is_comment_line(line:str)->bool:
    return line.startswith('/*')


def is_single_comment_line(line:str)->bool:
    return is_comment_line(line) and line.endswith('*/')


def is_multiline_comment(line:str)->bool:
    return is_comment_line(line) and not line.endswith('*/')


def is_multiline_comment_end(line:str)->bool:
    return line.endswith('*/')


def is_comment(line: str):
    lstrip = line.lstrip()
    return (len(lstrip) >= 2 and lstrip[0] == '/' and lstrip[1] == '/')


def remove_multiline_comments(text: str) -> str:
    clean = ''
    inMultiLineComment = False
    for line in text.splitlines():
        stripped = line.strip()
        if is_single_comment_line(stripped):
            continue
        if is_multiline_comment(stripped):
            inMultiLineComment = True
            continue
        if inMultiLineComment:
            if is_multiline_comment_end(stripped):
                inMultiLineComment = False
            continue
        clean += line.rstrip() + '\n'
    return clean


def remove_includes(text: str) -> str:
    clean = ''
    for line in text.splitlines():
        if is_include(line):
            continue
        clean += line + '\n'
    return clean


def remove_comments(text: str) -> str:
    clean = ''
    for line in text.splitlines():
        if is_comment(line):
            continue
        clean += line.rstrip() + '\n'
    return clean


def remove_multiblanks(text: str):
    return re.sub(r'[\r\n][\r\n]{2,}', '\n\n', text)


def clean_file(text: str) -> str:
    text = text.replace('#pragma once', '')
    return remove_multiblanks(remove_includes(remove_multiline_comments(remove_comments(text))))


def write_headers(headers):
    """
    Include header files "recursively" based on their inter-dependency.
    """
    global g_include

    dependencies = {}   
    for header in headers:
        short_header = header.replace(g_include, '')
        dependencies[short_header] = find_includes(header)
    dependencies.pop('H3API.hpp') # not needed
    dependencies.pop('patcher_x86.hpp') # handled at end
    dependencies.pop('h3api/PreprocessorCleanup.hpp') # handled at end
    
    written_headers = set()
    single_header   = ''

    print('Writing headers...')
    i = 1
    num = len(dependencies)
    while len(dependencies) > 0:
        for header, deps in dependencies.items():
            if can_be_written(deps, written_headers):
                print(f'{i}/{num} {header}')
                i += 1
                written_headers.add(header)
                single_header += open(os.path.join(g_include, header), 'r',encoding='utf8').read()
        for header in written_headers:
            if header in dependencies:
                dependencies.pop(header)
    print('All headers written!')

    return single_header


def write_sources(sources):
    """
    Sources are written after header and have therefore no need to look at dependencies.
    """
    global g_include

    print('Printing sources...')
    combined_sources = ''
    i = 1
    num = len(sources)
    for source in sources:
        combined_sources += open(os.path.join(g_include, source), 'r',encoding='utf8').read()
        print(f'{i}/{num} {source.replace(g_include, '')}')
        i += 1
    print('All sources written!')

    return combined_sources


def run():
    start_time = time.time()
    headers, sources = collect_files(g_include)
    single_header    = write_headers(headers) + write_sources(sources)

    print('Doing some cleanup...')
    single_header = clean_file(single_header)
    prep_cleanup  = clean_file(open('include/h3api/PreprocessorCleanup.hpp','r',encoding='utf8').read())
    patcher_x86   = clean_file(open('include/patcher_x86.hpp','r',encoding='utf8').read()[3:]) # skip over BOM

    print('Writing single header file...')
    single_template = open('scripts/single.template', 'r', encoding='utf8').read()      \
                                .replace('$API$', single_header)                        \
                                .replace('$CLEANUP$', prep_cleanup)                     \
                                .replace('$PATCHER_X86$', patcher_x86)                  \
                                .replace('$DATE$', datetime.now().strftime("%Y-%m-%d")) \
                                .replace('\n\n\n','\n\n') # last-second cleanup missed elsewhere

    open('single_header/H3API.hpp', 'w', encoding='utf8').write(single_template)
    total_time = time.time() - start_time
    print(f'Completed all tasks in {total_time:.4f} seconds.')


if __name__ == '__main__':
    run()