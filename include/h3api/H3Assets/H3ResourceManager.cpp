//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3ResourceManager.hpp"
#include "h3api/H3Assets/H3Resource.hpp"

namespace h3
{
    _H3API_ H3ResourceManager::Node* H3ResourceManager::FindItem(LPCSTR name)
    {
        iterator it = Find(name);
        if (it == end())
            return nullptr;
        return it.Get();
    }
    _H3API_ VOID H3ResourceManager::AddItem(H3ResourceItem* item)
    {
        H3ResourceItemData res(item->GetName());
        struct returnValues /* std::pair<Node*, bool>*/
        {
            Node* node;
            BOOL8 inserted;
        }retValues;

        THISCALL_3(returnValues&, 0x55DDF0, this, &retValues, &res);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(Node* node)
    {
        Node* temp;
        THISCALL_3(VOID, 0x55DF20, this, &temp, node);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(LPCSTR name)
    {
        if (!name)
            return;
        Node* node = FindItem(name);
        if (node == m_root)
            return;
        if (libc::strcmpi(node->data.m_name, name))
            return;
        RemoveItem(node);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(const iterator& iter)
    {
        if (iter != end())
            RemoveItem(iter.Get());
    }
} /* namespace h3 */
