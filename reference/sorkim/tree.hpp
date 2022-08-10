#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include "utils.hpp"

namespace ft 
{
	template <typename T>
	struct Node
	{
		typedef Node*			node_ptr;
		typedef const Node*		const_node_ptr;
		typedef size_t 			size_type;

		T 			_data;
		node_ptr 	_right;
		node_ptr 	_left;
		node_ptr 	_parent;
		size_type 	_height;

		Node(T _data) : _data(_data), _right(NULL), _left(NULL), _parent(NULL), _height(1) {}
	};

	template <typename node_ptr>
	node_ptr next_node(node_ptr x)
	{
		if (x->_right)
		{
			x = x->_right;
			while (x->_left)
				x = x->_left;
		}
		else
		{
			node_ptr y = x->_parent;
			while (x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			if (x->_right != y)
				x = y;
		}
		return x;
	}

	template <typename node_ptr>
	node_ptr prev_node(node_ptr x)
	{
		if (x->_left)
		{
			node_ptr y = x->_left;
			while (y->_right)
				y = y->_right;
			x = y;
		}
		else
		{
			node_ptr y = x->_parent;
			while (x == y->_left)
			{
				x = y;
				y = y->_parent;
			}
			x = y;
		}
		return x;
	}


	template <typename T,
			typename Comp,
			typename Alloc = std::allocator<T> >
	class AVLTree
	{
	public:
		typedef T value_type;
		typedef Comp value_compare;
		typedef typename Node<value_type>::node_ptr node_ptr;
		typedef typename Node<value_type>::size_type size_type;
		typedef typename Alloc::template rebind<Node<T> >::other allocator_type;

	private:
		node_ptr _root;
		node_ptr _end;
		size_type _size;
		allocator_type _alloc;
		value_compare _comp;

		size_type max(size_type a, size_type b)
		{
			return (a > b) ? a : b;
		}

		size_type height(node_ptr node)
		{
			return (node == NULL) ? 0 : node->_height;
		}

		int get_balance_factor(node_ptr node)
		{
			return (node == NULL) ? 0 : height(node->_left) - height(node->_right);
		}

		node_ptr find_min_node(node_ptr node) const
		{
			node_ptr min = node;

			if (min != NULL)
				while (min->_left)
					min = min->_left;

			return min;
		}

		node_ptr find_max_node(node_ptr node) const
		{
			node_ptr max = node;
			if (max != NULL)
				while (max->_right)
					max = max->_right;

			return max;
		}

		//   P (center) is going up and will replace Q (target)
			//
			//
			//               y                                x              |
			//              / \     RIGHT ROTATION           / \             |
			//             x   C   ------------------->>>   A   y            |
			//            / \                                  / \           |
			//           A   B                                B   C          |

		node_ptr right_rotate(node_ptr y)
		{
			node_ptr x = y->_left;

			if (x->_right != NULL)
				x->_right->_parent = y;

			x->_parent = y->_parent;
			y->_parent = x;
			y->_left = x->_right;
			x->_right = y;

			y->_height = max(height(y->_left), height(y->_right)) + 1;
			x->_height = max(height(x->_left), height(x->_right)) + 1;

			return x;
		}

		//   P (center) is going up and will replace Q (target)
			//
			//
			//               y                                x              |
			//              / \     LEFT ROTATION            / \             |
			//             x   C   <<<-------------------   A   y            |
			//            / \                                  / \           |
			//           A   B                                B   C          |

		node_ptr left_rotate(node_ptr x)
		{
			node_ptr y = x->_right;

			if (y->_left != NULL)
				y->_left->_parent = x;
				
			y->_parent = x->_parent;
			x->_parent = y;
			x->_right = y->_left;
			y->_left = x;

			x->_height = max(height(x->_left), height(x->_right)) + 1;
			y->_height = max(height(y->_left), height(y->_right)) + 1;

				return y;
		}

		node_ptr insert_node(node_ptr node, const value_type data, node_ptr parent = NULL)
		{
			if (node == NULL)
			{
				node = _alloc.allocate(1);
				_alloc.construct(node, data);
				node->_parent = parent;
				_size += 1;
				return node;
			}
			else if (_comp(data, node->_data))
				node->_left = insert_node(node->_left, data, node);
			else if (_comp(node->_data, data))
				node->_right = insert_node(node->_right, data, node);
			else
				return node;


			node->_height = max(height(node->_left), height(node->_right)) + 1;
			int balance_factor = get_balance_factor(node);
			if (balance_factor > 1)
			{
				if (_comp(data, node->_left->_data))
					return right_rotate(node);
				else
				{
					node->_left = left_rotate(node->_left);
					return right_rotate(node);
				}
			}
			else if (balance_factor < -1)
			{
				if (_comp(node->_right->_data, data))
					return left_rotate(node);
				else
				{
					node->_right = right_rotate(node->_right);
					return left_rotate(node);
				}
			}
			return node;
		}

		node_ptr delete_node(node_ptr node, value_type data)
		{
			if (node == NULL)
				return node;
			else if (_comp(data, node->_data))
				node->_left = delete_node(node->_left, data);
			else if (_comp(node->_data, data))
				node->_right = delete_node(node->_right, data);
			else
			{
				if (node->_left == NULL || node->_right == NULL)
				{
					node_ptr tmp1 = node->_left ? node->_left : node->_right;
					if (!tmp1)
					{
						tmp1 = node;
						node = NULL;
					}
					else
					{
						node_ptr tmp2 = node;
						tmp1->_parent = node->_parent;
						node = tmp1;
						tmp1 = tmp2;
					}
					_alloc.deallocate(tmp1, 1);
					_size -= 1;
				}
				else
				{
					node_ptr tmp = find_min_node(node->_right);

					node_ptr new_node = _alloc.allocate(1);
					_alloc.construct(new_node, tmp->_data);
					new_node->_parent = node->_parent;
					new_node->_right = node->_right;
					new_node->_left = node->_left;
					node->_right->_parent = new_node;
					node->_left->_parent = new_node;
					_alloc.deallocate(node, 1);
					node = new_node;
					node->_right = delete_node(node->_right, tmp->_data);
				}
			}
			if (node == NULL)
				return node;

			node->_height = 1 + max(height(node->_left), height(node->_right));
			int balance_factor = get_balance_factor(node);
			if (balance_factor > 1)
			{
				if (get_balance_factor(node->_left) >= 0)
					return right_rotate(node);
				else
				{
					node->_left = left_rotate(node->_left);
					return right_rotate(node);
				}
			}
			else if (balance_factor < -1)
			{
				if (get_balance_factor(node->_right) <= 0)
					return left_rotate(node);
				else
				{
					node->_right = right_rotate(node->_right);
					return left_rotate(node);
				}
			}
			return node;
		}

		node_ptr empty(node_ptr node)
		{
			if (node != NULL)
			{
				empty(node->_left);
				empty(node->_right);
				_alloc.deallocate(node, 1);
			}
			return NULL;
		}

		node_ptr find_node(node_ptr node, const value_type val) const
		{
			if (node == NULL)
				return NULL;
			else if (_comp(val, node->_data))
				return find_node(node->_left, val);
			else if (_comp(node->_data, val))
				return find_node(node->_right, val);

			return node;
		}

	public:
		AVLTree(value_compare c) : _comp(c)
		{
			_root = NULL;
			_size = 0;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, value_type());
		}

		~AVLTree()
		{
			_root = empty(_root);
			_alloc.deallocate(_end, 1);
		}

		void insert(value_type data)
		{
			_root = insert_node(_root, data);
			_root->_parent = _end;
			_end->_left = _root;
		}

		void erase(value_type val)
		{
			_root = delete_node(_root, val);
			if (_root)
			{
				_root->_parent = _end;
				_end->_left = _root;
			}
		}

		bool is_empty() const
		{
			return (_size == 0);
		}

		void clear()
		{
			_root = empty(_root);
			_size = 0;
		}

		size_type get_size() const
		{
			return _size;
		}

		size_type get_max_size() const
		{
			return _alloc.max_size();
		}

		node_ptr get_end_node() const
		{
			return _end;
		}

		node_ptr get_min_node() const
		{
			return find_min_node(_root);
		}

		node_ptr get_max_node() const
		{
			return find_max_node(_root);
		}

		node_ptr find(value_type val) const
		{
			node_ptr node = find_node(_root, val);
			if (node == NULL)
				return _end;
			return node;
		}

		void swap(AVLTree &x)
		{
			node_ptr tmp_begin = x._root;
			node_ptr tmp_end = x._end;
			size_type tmp_size = x._size;

			x._size = _size;
			x._root = _root;
			x._end = _end;
			
			_size = tmp_size;
			_root = tmp_begin;
			_end = tmp_end;
		}

		node_ptr lower_bound(const value_type val) const
		{
			node_ptr current = find_min_node(_root);

			while (current && current != _end)
			{
				if (!_comp(current->_data, val))
					return current;
				current = next_node(current);
			}
			return _end;
		}

		node_ptr upper_bound(const value_type val) const
		{
			node_ptr current = find_min_node(_root);

			while (current && current != _end)
			{
				if (_comp(val, current->_data))
					return current;
				current = next_node(current);
			}
			return _end;
		}
	};
}

#endif // AVL_HPP
