//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
    template<typename T, UINT NilNode> struct H3Set;
#ifdef _H3API_TEMPLATE_DECLARE_
    template<typename T, UINT NilNode>
    using Set = H3Set<T, NilNode>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

#pragma pack(push, 4)
    /**
     * @brief A representation of std::set as found within h3
     * The container is not complete (and never will due to complexity)
     * It only exists to give access and to derive required structures from
     * @tparam T Stored elements with comparison int operator<(const&)
     * @tparam NilNode The address of the static nil node
     */
    template<typename T, UINT NilNode = 0>
    struct H3Set
    {
        _H3API_SIZE_(0x10);

        struct Node
        {
            Node* left;    /**< @brief [00] left child*/
            Node* parent;  /**< @brief [04] parent node*/
            Node* right;   /**< @brief [08] right child*/
            T     data;    /**< @brief [0C] The data for this node*/
            BOOL  isBlack; /**< @brief [0C + sizeof(T)] whether the node is black(1) or red(0)*/

            T* operator->() const { return &data; }
            T& operator*() const  { return data; }
        };
        typedef typename Node* NodePtr;
    protected:
        h3unk8 _allocator;  /**< @brief [00] default allocator, C++ requires 1 byte even if no body*/
        h3unk8 _keyCompare; /**< @brief [01] default key comparator, C++ requires 1 byte even if no body*/
        Node*  m_root;      /**< @brief [04] The anchor node of the tree*/
        BOOL8  m_multiset;  /**< @brief [08] accept duplicate keys or not*/
        UINT32 m_count;     /**< @brief [0C] The number of nodes in the tree*/

        Node* head() const;

    #ifdef _H3API_CPLUSPLUS11_
        static constexpr Node** _Nil = reinterpret_cast<Node**>(NilNode);
    #else
        _H3API_FORCEINLINE_ static Node** _Nil();
    #endif
    public:

        /**
         * @brief An iterator to go over H3Set
         */
        struct iterator
        {
        protected:
            Node* m_node;
            Node* endNode() const;
        public:
            iterator& operator++();
            iterator operator++(int);
            T& operator*() const;
            T* operator->() const;
            bool operator==(const iterator& it) const;
            bool operator!=(const iterator& it) const;
            iterator(NodePtr node);
            Node* Get() const;
        };
        iterator begin();
        iterator begin() const;
        iterator end();
        iterator end() const;

        /**
         * @brief Obtains the static nil node from its templated address
         * @return NodePtr nil node
        */
        NodePtr  Nil() const;
        /**
         * @brief The number of nodes currently residing in the set
         * @return 0...n nodes
        */
        UINT Count() const;
        /**
         * @brief Finds matching data to the specified key within the set
         * @param key A key to the data to find
         * @return An iterator to the matching object if found, otherwise to end() iterator
        */
        iterator Find(const T& key) const;

        // Insert is not provided, specialized sets can have it (e.g. Resource Manager)
    };
    _H3API_ASSERT_SIZE_(H3Set<h3unk>);
#pragma pack(pop) /* align-4 */

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::head() const
    {
        return m_root->parent;
    }

#ifndef _H3API_CPLUSPLUS11_
    template<typename T, UINT NilNode>
    inline typename _H3API_FORCEINLINE_ H3Set<T, NilNode>::Node** H3Set<T, NilNode>::_Nil()
    {
        return reinterpret_cast<Node**>(NilNode);
    }
#endif

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::NodePtr H3Set<T, NilNode>::Nil() const
    {
        return NodePtr(PtrAt(NilNode));
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::begin()
    {
        return iterator(m_root->left);
    }
    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::begin() const
    {
        return iterator(m_root->left);
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::end()
    {
        return iterator(m_root);
    }
    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::end() const
    {
        return iterator(m_root);
    }

    template<typename T, UINT NilNode>
    inline UINT H3Set<T, NilNode>::Count() const
    {
        return m_count;
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::Find(const T& key) const
    {
        NodePtr end_node = NodePtr(PtrAt(NilNode));
        NodePtr it = head();
        NodePtr result = m_root;
        while (it != end_node)
        {
            if (it->data < key)
                it = it->right;
            else
            {
                result = it;
                it = it->left;
            }
        }
        if (result == end_node)
            return end();
        if (key < result->data)
            return end();
        return iterator(result);
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::iterator::endNode() const
    {
        return NodePtr(PtrAt(NilNode));
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator& H3Set<T, NilNode>::iterator::operator++()
    {
        NodePtr end_node = endNode();
        NodePtr node = m_node->right;
        if (node != end_node)
        {
            while (node->left != end_node) // min
                node = node->left;
            m_node = node;
        }
        else
        {
            NodePtr parent = m_node->parent;
            while (parent->right == m_node)
            {
                m_node = parent;
                parent = m_node->parent;
            }
            if (m_node->right != parent)
                m_node = parent;
        }
        return *this;
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::iterator::operator++(int)
    {
        iterator it(m_node);
        ++(*this);
        return it;
    }

    template<typename T, UINT NilNode>
    inline T& H3Set<T, NilNode>::iterator::operator*() const
    {
        return m_node->data;
    }

    template<typename T, UINT NilNode>
    inline T* H3Set<T, NilNode>::iterator::operator->() const
    {
        return &m_node->data;
    }

    template<typename T, UINT NilNode>
    inline bool H3Set<T, NilNode>::iterator::operator==(const iterator& it) const
    {
        return m_node == it.m_node;
    }

    template<typename T, UINT NilNode>
    inline bool H3Set<T, NilNode>::iterator::operator!=(const iterator& it) const
    {
        return m_node != it.m_node;
    }

    template<typename T, UINT NilNode>
    inline H3Set<T, NilNode>::iterator::iterator(NodePtr node) :
        m_node(node)
    {
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::iterator::Get() const
    {
        return m_node;
    }

}
