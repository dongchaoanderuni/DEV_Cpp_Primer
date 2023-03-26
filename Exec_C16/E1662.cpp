#include "Headfile.h"
#include "Sales_data.h"
#include "HashSalesData.h"

using namespace std;

int main()
{
    Sales_data book1("book1", 10, 3.99);
    Sales_data book2("book2", 20, 4.99);
    Sales_data book3("book3", 30, 5.99);
    Sales_data book4("book4", 40, 6.99);

    // create unordered_multiset of Sales_data objects
    std::unordered_multiset<Sales_data, std::hash<Sales_data>> bookstore;
    // declare hash function object for Sales_data
    auto hash_sales_data = std::hash<Sales_data>();

    // insert Sales_data objects into the unordered_multiset
    bookstore.insert(book1);
    bookstore.insert(book2);
    bookstore.insert(book3);
    bookstore.insert(book4);

    // print the contents of the unordered_multiset
    for (const auto& book : bookstore)
    {
        std::cout << book << std::endl;
    }

    return 0;
}
