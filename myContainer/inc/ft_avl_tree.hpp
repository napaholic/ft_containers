//
// Created by jaewkim on 2022/08/10.
//

#ifndef MYCONTAINER_FT_AVL_TREE_HPP
#define MYCONTAINER_FT_AVL_TREE_HPP

#include "config.hpp"

namespace ft {
	// AVL tree implementation in C++
	
	template<typename T>
	struct avl_node {
		typedef avl_node *node_ptr;
		typedef size_t size_type;
		
		T 																_value;
		node_ptr 														_right;
		node_ptr 														_left;
		node_ptr 														_parent;
		size_type 														_height;
		int 															_alloc_chk;
		
		avl_node() : _value(), _right(ft_nullptr), _left(ft_nullptr), _parent(ft_nullptr), _height(1), _alloc_chk(1) {}
		
		avl_node(const T &value, avl_node *parent = ft_nullptr,
				 avl_node *left = ft_nullptr, avl_node *right = ft_nullptr, size_type height = 1)
				: _value(value), _right(right), _left(left), _parent(parent), _height(height), _alloc_chk(1) {}
		
		avl_node(const avl_node &ref)
				: _value(ref._value),
				  _right(ref._right),
				  _left(ref._left),
				  _parent(ref._parent),
				  _height(ref._height),
				  _alloc_chk(1) {}
		
		virtual ~avl_node() {
			_alloc_chk = 0;
		}
		
		avl_node &operator=(const avl_node &ref) {
			if (this != &ref) {
				this->_value = ref._value;
				this->_parent = ref._parent;
				this->_left = ref._left;
				this->_right = ref._right;
				this->_height = ref._height;
			}
			return (*this);
		}
		
		bool operator==(const avl_node &ref) const {
			return (this->value == ref._value);
		}
		
		bool operator!=(const avl_node &ref) const {
			return (this->_value != ref._value);
		}
	};
	
	template<class T1, class T2>
	bool operator==(const avl_node<T1> &lhs, const avl_node<T2> &rhs) {
		return lhs == rhs;
	}
	
	template<class T1, class T2>
	bool operator!=(const avl_node<T1> &lhs, const avl_node<T2> &rhs) {
		return lhs != rhs;
	}
	
	template<typename node_ptr>
	node_ptr next_node(node_ptr x) {
		if (x->_right) {
			x = x->_right;
			while (x->_left)
				x = x->_left;
		} else {
			node_ptr y = x->_parent;
			if (y == ft_nullptr)
				return ft_nullptr;
			while (x == y->_right) {
				x = y;
				y = y->_parent;
			}
			if (x->_right != y)
				x = y;
		}
		return x;
	}
	
	template<typename node_ptr>
	node_ptr prev_node(node_ptr x) {
		if (x->_left) {
			node_ptr y = x->_left;
			while (y->_right)
				y = y->_right;
			x = y;
		} else {
			node_ptr y = x->_parent;
			while (x == y->_left) {
				x = y;
				y = y->_parent;
			}
			x = y;
		}
		return x;
	}
	
	template<typename T, typename Compare, typename Alloc = std::allocator<T> >
	class AvlTree {
	private:
		typedef ft::avl_node<T>											node_type;
	
	public:
		typedef T														value_type;
		typedef Compare 												value_compare;
		typedef typename avl_node<value_type>::node_ptr 				node_ptr;
		typedef typename avl_node<value_type>::size_type 				size_type;
		typedef typename Alloc::template rebind<node_type>::other		alloc_type;
	
	private:
		node_ptr														__root;
		node_ptr														__end;
		size_type														__size;
		alloc_type														__alloc;
		value_compare													__comp;
		int																__alloc_chk;
	
	public:
		//constructor
		AvlTree(value_compare const& c, alloc_type const& alloc) : __alloc(alloc), __comp(c) {
			__root = ft_nullptr;
			__size = 0;
			__end = __alloc.allocate(1);
			__alloc.construct(__end, node_type());
			__alloc_chk = 1;
		}
		AvlTree(value_compare const& c) : __comp(c) {
			__root = ft_nullptr;
			__size = 0;
			__end = __alloc.allocate(1);
			__alloc.construct(__end, node_type());
			__alloc_chk = 1;
		}
		
//		AvlTree(const AvlTree &ref)
//		: __comp(ref.__comp), __alloc(ref.__alloc), __{
//			__root = ref;
//			__size = 0;
//			__end = __alloc.allocate(1);
//			__alloc.construct(__end, node_type());
//			__alloc_chk = 1;
//		}
		
		//destructor
		~AvlTree() {
			__alloc_chk = 0;
			__root = empty(__root);
			//empty(__end);
			//__alloc.destroy(__end);
			if (__end->_left)
				__end->_left = ft_nullptr;
			if (__end->_alloc_chk) {
				__alloc.destroy(__end);
				__alloc.deallocate(__end, 1);
			}
			//__alloc.deallocate(__end, 1);
		}
	private:
		size_type max(size_type a, size_type b) {
			return (a > b) ? a : b;
		}
		
		size_type height(node_ptr node) {
			return (node == ft_nullptr) ? 0 : node->_height;
		}
		
		int get_balance_factor(node_ptr node) {
			return (node == ft_nullptr) ? 0 : height(node->_left) - height(node->_right);
		}
		
		node_ptr right_rotate(node_ptr y) {
			node_ptr x = y->_left;
			
			if (x->_right != ft_nullptr)
				x->_right->_parent = y;
			x->_parent = y->_parent;
			y->_parent = x;
			y->_left = x->_right;
			x->_right = y;
			y->_height = max(height(y->_left), height(y->_right)) + 1;
			x->_height = max(height(x->_left), height(x->_right)) + 1;
			return (x);
		}
		
		node_ptr left_rotate(node_ptr x) {
			node_ptr y = x->_right;
			
			if (y->_left != ft_nullptr)
				y->_left->_parent = x;
			y->_parent = x->_parent;
			x->_parent = y;
			x->_right = y->_left;
			y->_left = x;
			x->_height = max(height(x->_left), height(x->_right)) + 1;
			y->_height = max(height(y->_left), height(y->_right)) + 1;
			return (y);
		}
		
		node_ptr insert_node(node_ptr node, const value_type data, node_ptr parent = ft_nullptr) {
			if (node == ft_nullptr) {
				node = __alloc.allocate(1);
				__alloc.construct(node, data);
				node->_parent = parent;
				__size += 1;
				return (node);
			} else if (__comp(data, node->_value))
				node->_left = insert_node(node->_left, data, node);
			else if (__comp(node->_value, data))
				node->_right = insert_node(node->_right, data, node);
			else
				return (node);
			node->_height = max(height(node->_left), height(node->_right)) + 1;
			int balance_factor = get_balance_factor(node);
			if (balance_factor > 1) {
				if (__comp(data, node->_left->_value))
					return (right_rotate(node));
				else {
					node->_left = left_rotate(node->_left);
					return right_rotate(node);
				}
			} else if (balance_factor < -1) {
				if (__comp(node->_right->_value, data))
					return left_rotate(node);
				else {
					node->_right = right_rotate(node->_right);
					return left_rotate(node);
				}
			}
			return node;
		}
		
		
		//delete
		node_ptr delete_node(node_ptr node, value_type data) {
			if (node == ft_nullptr)
				return node;
			else if (__comp(data, node->_value))
				node->_left = delete_node(node->_left, data);
			else if (__comp(node->_value, data))
				node->_right = delete_node(node->_right, data);
			else {
				if (node->_left == ft_nullptr || node->_right == ft_nullptr) {
					node_ptr tmp1 = node->_left ? node->_left : node->_right;
					if (!tmp1) {
						tmp1 = node;
						node = ft_nullptr;
						if (tmp1->_parent->_left == tmp1)
							tmp1->_parent->_left = ft_nullptr;
						else
							tmp1->_parent->_right = ft_nullptr;
					} else {
						node_ptr tmp2 = node;
						tmp1->_parent = node->_parent;
						if (tmp2->_parent->_left == tmp2)
							tmp2->_parent->_left = tmp1;
						else
							tmp2->_parent->_right = tmp1;
						node = tmp1;
						tmp1 = tmp2;
					}
					__alloc.destroy(tmp1);
					__alloc.deallocate(tmp1, 1);
					__size -= 1;
				} else {
					node_ptr tmp_min_node = find_min_node(node->_right);
					if (tmp_min_node->_right) {
						tmp_min_node->_right->_parent = tmp_min_node->_parent;
						if (tmp_min_node->_parent->_left == tmp_min_node)
							tmp_min_node->_parent->_left = tmp_min_node->_right;
						else
							tmp_min_node->_parent->_right = tmp_min_node->_right;
					}
					tmp_min_node->_parent = node->_parent;
					tmp_min_node->_left = node->_left;
					if (node->_right == tmp_min_node)
						tmp_min_node->_right = ft_nullptr;
					else
						tmp_min_node->_right = node->_right;
					if (node->_parent->_left == node)
						node->_parent->_left = tmp_min_node;
					else
						node->_parent->_right = tmp_min_node;
					if (node->_left != tmp_min_node)
						node->_left->_parent = tmp_min_node;
					if (node->_right != tmp_min_node)
						node->_right->_parent = tmp_min_node;
					__alloc.destroy(node);
					__alloc.deallocate(node, 1);
					__size -= 1;
					node = tmp_min_node;
					
					/*node_ptr new_node = __alloc.allocate(1);
					__alloc.construct(new_node, tmp->_value);
					new_node->_parent = node->_parent;
					new_node->_right = node->_right;
					new_node->_left = node->_left;
					node->_right->_parent = new_node;
					node->_left->_parent = new_node;
					__alloc.destroy(node);
					__alloc.deallocate(node, 1);
					node = new_node;
					__alloc.construct(node, tmp->_value);
					node->_parent = tmp_parent;
					node->_left = tmp_left;
					node->_right = tmp_right;
					node->_right = delete_node(node->_right, tmp->_value);*/
				}
			}
			if (node == ft_nullptr)
				return node;
			node->_height = 1 + max(height(node->_left), height(node->_right));
			int balance_factor = get_balance_factor(node);
			if (balance_factor > 1) {
				if (get_balance_factor(node->_left) >= 0)
					return right_rotate(node);
				else {
					node->_left = left_rotate(node->_left);
					return right_rotate(node);
				}
			} else if (balance_factor < -1) {
				if (get_balance_factor(node->_right) <= 0)
					return left_rotate(node);
				else {
					node->_right = right_rotate(node->_right);
					return left_rotate(node);
				}
			}
			return node;
		}
		
		node_ptr empty(node_ptr node) {
			if (node != ft_nullptr) {
				empty(node->_left);
				empty(node->_right);
				if (node->_alloc_chk) {
					__alloc.destroy(node);
					__alloc.deallocate(node, 1);
				}
				node = ft_nullptr;
			}
			return (ft_nullptr);
		}
		
		node_ptr find_node(node_ptr node, const value_type val) const {
			if (node == ft_nullptr)
				return ft_nullptr;
			else if (__comp(val, node->_value))
				return find_node(node->_left, val);
			else if (__comp(node->_value, val))
				return find_node(node->_right, val);
			return node;
		}
	
	public:
		
		void insert(value_type data) {
			__root = insert_node(__root, data);
			__root->_parent = __end;
			__end->_left = __root;
		}
		
		void erase(value_type val) {
			__root = delete_node(__root, val);
			if (__root) {
				__root->_parent = __end;
				__end->_left = __root;
			}
		}
		
		node_ptr find_min_node(node_ptr node) const {
			node_ptr min = node;
			
			if (min != ft_nullptr)
				while (min->_left)
					min = min->_left;
			return (min);
		}
		
		node_ptr find_max_node(node_ptr node) const {
				node_ptr max = node;
				if (max != ft_nullptr)
					while (max->_right)
						max = max->_right;
				return (max);
		}
		bool is_empty() const {
				return (__size == 0);
		}
		void clear() {
				__root = empty(__root);
				__size = 0;
		}
		size_type get_size() const {
				return __size;
		}
		size_type get_max_size() const {
				return __alloc.max_size();
		}
		node_ptr get_root_node() const {
			return __root;
		}
		
		node_ptr get_end_node() const {
			return __end;
		}
		
		node_ptr get_min_node() const {
			return find_min_node(__root);
		}
		node_ptr get_max_node() const {
			return find_max_node(__root);
		}
		
		node_ptr find(value_type val) const {
			node_ptr node = find_node(__root, val);
			if (node == ft_nullptr)
				return this->get_end_node();
			return node;
		}
		
		void swap(AvlTree &ref) {
			node_ptr tmp_begin = ref.__root;
			node_ptr tmp_end = ref.__end;
			size_type tmp_size = ref.__size;
			alloc_type tmp_alloc = ref.__alloc;
			value_compare tmp_comp = ref.__comp;
			
			ref.__size = __size;
			ref.__root = __root;
			ref.__end = __end;
			ref.__alloc = __alloc;
			ref.__comp = __comp;
			
			__size = tmp_size;
			__root = tmp_begin;
			__end = tmp_end;
			__alloc = tmp_alloc;
			__comp = tmp_comp;
		}
	};
}

// Delete a node
/*
Node *deleteNode(Node *root, int key) {
	// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else
				*root = *temp;
			free(temp);
		} else {
			Node *temp = nodeWithMimumValue(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	
	if (root == NULL)
		return root;
	
	// Update the balance factor of each node and
	// balance the tree
	root->height = 1 + max(height(root->left),
						   height(root->right));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) {
		if (getBalanceFactor(root->left) >= 0) {
			return rightRotate(root);
		} else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (getBalanceFactor(root->right) <= 0) {
			return leftRotate(root);
		} else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}*/

#endif //MYCONTAINER_FT_AVL_TREE_HPP
