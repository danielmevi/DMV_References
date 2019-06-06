/*
 * CPP Guidelines: Express ideas directly in code
 *
 * This source code examples the use of background code to protect code against
 * wrong interpretations of functions, variables, etc
 *
 * Recomendations from Pablo Halpern about to have an implementation that works at compile and run time with constexpr
 *
 * Features:
 * Implementation provides compile time constructors for specific data types (year, month, day) if the data is known at
 * such compilation phase
 * Implementation also provides set parameters interoperability of data type Date
 *
 * TODO: APPLY profiler and static analysis
 * TODO: Add compile checks if all year, month and day are known at compile time
 */

#include <cstdint>
#include <iostream>
#include <sstream>
#include <type_traits>
#include <memory>
#include <string>


/////////////////////////////////////////////////////////////////////////////////
// Types
//

struct year_t
{
  unsigned value;
  constexpr year_t( unsigned N ) : value(N) {} 
};

struct month_t
{
  unsigned value;
  constexpr month_t( unsigned N ) : value(N) {}
};

struct day_t
{
  unsigned value;
  constexpr day_t( unsigned N ) : value(N) {}
};

/////////////////////////////////////////////////////////////////////////////////
// Parameter types
//

constexpr year_t 
operator ""_year (const unsigned long long int y)
{ return year_t(y); }

constexpr month_t
operator ""_month (const unsigned long long int m)
{ return month_t(m); }

constexpr day_t
operator ""_day (const unsigned long long int d)
{ return day_t(d); }

/////////////////////////////////////////////////////////////////////////////////
// Custom stream manipulation
//

std::ostream &operator<< (std::ostream &os, year_t const &date) { return os << date.value; } 
std::ostream &operator<< (std::ostream &os, month_t const &date) { return os << date.value; } 
std::ostream &operator<< (std::ostream &os, day_t const &date) { return os << date.value; } 

/////////////////////////////////////////////////////////////////////////////////

class Date 
{
    public:
      template <typename T, typename Y, typename Z>
      constexpr Date (T p1, Y p2, Z p3) :
                _year (_yearOf(p1,p2,p3)),
                _month (_monthOf(p1,p2,p3)),
                _day (_dayOf(p1,p2,p3))
      { }


      std::string 
      getDate()
      {
        std::stringstream date;
        date << _day.value << "/" << _month.value << "/" << _year.value;
        return date.str();
      }

      constexpr year_t
      year() const 
      {
        return _year;
      }
      
      constexpr month_t 
      month() const 
      {
        return _month;
      }
      
      constexpr day_t 
      day() const 
      {
        return _day;
      }

    private:
      
      template <typename... Tail>
      constexpr year_t _yearOf (year_t y, Tail...) { return y; }
      template <typename Head, typename... Tail>
      constexpr year_t _yearOf (Head, Tail... tail) { return _yearOf(tail...); }

      template <typename... Tail>
      constexpr month_t _monthOf (month_t m, Tail...) { return m; }
      template <typename Head, typename... Tail>
      constexpr month_t _monthOf (Head, Tail... tail) { return _monthOf(tail...); }

      template <typename... Tail>
      constexpr day_t _dayOf (day_t d, Tail...) { return d; }
      template <typename Head, typename... Tail>
      constexpr day_t _dayOf (Head, Tail... tail) { return _dayOf(tail...); }
      
      year_t _year;
      month_t _month;
      day_t _day;
};

int main()
{

  // Compile time

  Date date(2016_year, 10_month, 10_day);    // Prototype usage
  Date date2(5_month, 1_day, 2010_year);     // Prototype 2 usage
  //date3.setDate(2016, 10, 10);                           // Compilation error
  //date4.setDate(Month<20>(), Day<50>(), Year<99999>());  // Compilation error

  std::cout << "Year 1: " << date.year() << std::endl;
  std::cout << "Month 2: " << date2.month() << std::endl;
  std::cout << "Day 1: " << date.day() << std::endl;
  std::cout << date2.getDate() << std::endl;

  auto y = 1006_year; // Single prototype usage
  auto m = 12_month;  // Single prototype usage
  auto d = 30_day;    // Single prorotype usage

  //auto y1 = Year_v<9999>; // Compilation error
  //auto m1 = Month_v<76>;  // Compilation error
  //auto d1 = Day_v<101>;   // Compilation error

  std::cout << "Year: " << y << " Month: " << m << " Day: "  << d << std::endl;

  // Run time 
  
  unsigned y2;
  std::cout << "Year: ";
  std::cin >> y2;
  unsigned m2;
  std::cout << "Month: ";
  std::cin >> m2;
  unsigned d2;
  std::cout << "Day: ";
  std::cin >> d2;

  auto date3 = std::make_shared<Date>(year_t(y2), month_t(m2), day_t(d2));

  std::cout << "Year 3: " << date3->year() << std::endl;
  std::cout << "Month 3: " << date3->month() << std::endl;
  std::cout << "Day 3: " << date3->day() << std::endl;
  std::cout << date3->getDate() << std::endl;


  return 0;
}

/*
 *********************************
FIRST TRY

#include <cstdint>
#include <iostream>
#include <sstream>
#include <type_traits>

/////////////////////////////////////////////////////////////////////////////////
// Traits library
//

// General

template< typename T, typename U >
static constexpr auto is_not_same_v = !std::is_same<T,U>::value;

// Date tags

struct date_tag {};
struct yeart_tag : public date_tag {};
struct month_tag : public date_tag {};
struct day_tag  : public date_tag {};

// Date category with meta checks

template< unsigned N = 0 >
struct Year : std::integral_constant< unsigned, N >
{
  typedef yeart_tag date_category;
  static_assert( N < 9999, "ERROR: Exeeded Year max value definition... ");
};
template< unsigned N = 0 >
static constexpr auto Year_v = Year<N>::value;

template< unsigned N = 0 >
struct Month : std::integral_constant< unsigned, N >
{
  typedef month_tag date_category;
  static_assert( N < 13, "ERROR: Exeeded Month max value definition... ");
};
template< unsigned N = 0 >
static constexpr auto Month_v = Month<N>::value;

template< unsigned N = 0 >
struct Day : std::integral_constant< unsigned, N >
{
  typedef day_tag date_category;
  static_assert( N < 32, "ERROR: Exeeded Day max value definition... ");
};
template< unsigned N = 0 >
static constexpr auto Day_v = Day<N>::value;

// Date traits

template< typename T >
struct date_traits
{
  typedef typename T::date_category date_category;
};

/////////////////////////////////////////////////////////////////////////////////
// Types
//

struct value_t { unsigned value; };
struct year_t : value_t { year_t( unsigned N ) : value_t({N}) {} };
struct month_t : value_t { month_t( unsigned N ) : value_t({N}) {} };
struct day_t : value_t { day_t( unsigned N ) : value_t({N}) {} };

/////////////////////////////////////////////////////////////////////////////////
// Custom stream manipulation
//

std::ostream &operator<<( std::ostream &os, value_t const &date ) { return os << date.value; } 

/////////////////////////////////////////////////////////////////////////////////

class Date 
{
    public:
      Date() : _year(0), _month(0), _day(0){}

      // TODO: Add ability to receive 1, 2 or 3 parameters
      template< typename T, typename Y, typename Z >
      void
      setDate(T p1, Y p2, Z p3)
      {
        _setDate(p1, p2, p3);
      }

      std::string 
      getDate()
      {
        std::stringstream date;
        date << _day.value << "/" << _month.value << "/" << _year.value;
        return date.str();
      }

      year_t
      year() const 
      {
        return _year;
      }
      
      month_t 
      month() const 
      {
        return _month;
      }
      
      day_t 
      day() const 
      {
        return _day;
      }

    private:
      void _setDate(){}
      template <typename Head, typename... Tail>
      void _setDate(Head const &head, Tail const &... tail)
      {
        static_assert( is_not_same_v<Head, date_tag>, "ERROR: setDate only accept Year, Month and Day template struct as parameter..." );
        _setDates_argv(head, typename date_traits<Head>::date_category());
        _setDate(tail...);
      }

      void _setDates_argv(unsigned year, yeart_tag) { _year = year; }
      void _setDates_argv(unsigned month, month_tag) { _month = month; }
      void _setDates_argv(unsigned day, day_tag) { _day = day; }

      year_t _year;
      month_t _month;
      day_t _day;
};

int main()
{
  Date date;
  Date date2;
  Date date3;
  Date date4;

  date.setDate(Year<2016>(), Month<10>(), Day<10>());    // Prototype usage
  date2.setDate(Month<5>(), Day<1>(), Year<2010>());     // Prototype 2 usage
  //date3.setDate(2016, 10, 10);                           // Compilation error
  //date4.setDate(Month<20>(), Day<50>(), Year<99999>());  // Compilation error

  std::cout << "Year 1: " << date.year() << std::endl;
  std::cout << "Month 2: " << date2.month() << std::endl;
  std::cout << "Day 1: " << date.day() << std::endl;
  std::cout << date2.getDate() << std::endl;

  auto y = Year_v<1006>; // Single prototype usage
  auto m = Month_v<12>;  // Single prototype usage
  auto d = Day_v<30>;    // Single prorotype usage

  //auto y1 = Year_v<9999>; // Compilation error
  //auto m1 = Month_v<76>;  // Compilation error
  //auto d1 = Day_v<101>;   // Compilation error

  std::cout << "Year: " << y << " Month: " << m << " Day: "  << d << std::endl;

  return 0;
}


*/
