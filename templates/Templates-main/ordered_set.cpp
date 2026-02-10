#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Multiset, Multimap
template <typename T> using ordered_multiset_base = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_multimap_base = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
class orderedmultiset : public ordered_multiset_base<T> {
    using base = ordered_multiset_base<T>;
    public: 
        inline void eraseone(const T &_val){
            auto it = base::lower_bound(_val);
            if (it != base::end() && *it == _val)
                base::erase(it);
        }
};
template <typename T, typename U>
class orderedmultimap : public ordered_multimap_base<T, U> {
    using base = ordered_multimap_base<T, U>;
};