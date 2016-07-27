

// Aliases
template< bool B >
/using bool_constant = std::integral_constant<bool,B>; 
/
/template< typename T >
/using remove_cv_t = typename  std::remove_cv<T>::type;
/
/using true_type = bool_constant<true>;
/using false_type = bool_constant<false>;
/
template< bool B, typename T = void >
using enable_if_t = typename std::enable_if<B,T>::type;
/
/template< typename T >
/struct type_is { using type = T; };

/ Bases
/class Debug : public true_type{};
/class Production : public false_type {};

/ Conditions
/template< typename T >
/using is_debug = std::is_same< remove_cv_t<T>, Debug>; // TODO: Why compiler mentions that it requires template arguments?
/
/template< bool, typename T, typename >
/struct IF : type_is<T> {};
/template< typename T, typename F >
/struct IF<false, T, F> : type_is<F> {};
/template< bool B, typename T, typename F >
/using IF_t = typename IF<B, T, F>::type;

