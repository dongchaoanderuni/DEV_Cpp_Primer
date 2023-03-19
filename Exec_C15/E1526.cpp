#include "Headfile.h"
#include "Quote.h"

using namespace std;

void TestCaseForE1526(int testcase)
{
    switch (testcase) 
    {
        case 1: // Creating a Quote object
        {
            cout << "Creating a Quote object..." << endl;
            Quote q("111-222-333", 20.0); // Quote: constructor taking string and double
            cout << "Destroying the Quote object..." << endl;
            break;
        }

        case 2: // Creating a Bulk_Quote object
        {
            cout << "Creating a Bulk_Quote object..." << endl;
            Bulk_Quote bq("444-555-666", 20.0, 5, 0.1); // Bulk_Quote: constructor taking string, double, size_t and double
            cout << "Destroying the Bulk_Quote object..." << endl;
            break;
        }

        case 3: // Copy-constructing a Quote object
        {
            cout << "Copy-constructing a Quote object..." << endl;
            Quote q1("111-222-333", 20.0); // Quote: constructor taking string and double
            Quote q2(q1); // Quote: copy constructor
            cout << "Destroying the Quote objects..." << endl;
            break;
        }

        case 4: // Copy-constructing a Bulk_Quote object
        {
            cout << "Copy-constructing a Bulk_Quote object..." << endl;
            Bulk_Quote bq1("444-555-666", 20.0, 5, 0.1); // Bulk_Quote: constructor taking string, double, size_t and double
            Bulk_Quote bq2(bq1); // Bulk_Quote: copy constructor
            cout << "Destroying the Bulk_Quote objects..." << endl;
            break;
        }

        case 5: // Copy-assigning a Quote object
        {
            cout << "Copy-assigning a Quote object..." << endl;
            Quote q1("111-222-333", 20.0); // Quote: constructor taking string and double
            Quote q2; // Quote: constructor
            q2 = q1; // Quote: copy assignment operator
            cout << "Destroying the Quote objects..." << endl;
            break;
        }

        case 6: // Copy-assigning a Bulk_Quote object
        {
            cout << "Copy-assigning a Bulk_Quote object..." << endl;
            Bulk_Quote bq1("444-555-666", 20.0, 5, 0.1); // Bulk_Quote: constructor taking string, double, size_t and double
            Bulk_Quote bq2; // Bulk_Quote: constructor
            bq2 = bq1; // Bulk_Quote: copy assignment operator
            cout << "Destroying the Bulk_Quote objects..." << endl;
            break;
        }

        case 7: // Move-constructing a Quote object
        {
            cout << "Move-constructing a Quote object..." << endl;
            Quote q1("111-222-333", 20.0); // Quote: constructor taking string and double
            Quote q2(std::move(q1)); // Quote: std::move constructor
            cout << "Destroying the Quote objects..." << endl;
            break;
        }

        case 8: // Move-constructing a Bulk_Quote object
        {
            cout << "Move-constructing a Bulk_Quote object..." << endl;
            Bulk_Quote bq1("444-555-666", 20.0, 5, 0.1); // Bulk_Quote: constructor taking string, double, size_t and double
            Bulk_Quote bq2 = std::move(bq1); // Bulk_Quote: std::move constructor
            
            break;
        }
        
        case 9: // Move-assigning a Quote object
        {
            cout << "Move-assigning a Quote object..." << endl;
            Quote q1("111-222-333", 20.0); // Quote: constructor taking string and double
            Quote q2; // Quote: constructor
            q2 = std::move(q1); // Quote: std::move assignment operator
            cout << "Destroying the Quote objects..." << endl;
            break;
        }

        case 10: // Move-assigning a Bulk_Quote object
        {
            cout << "Move-assigning a Bulk_Quote object..." << endl;
            Bulk_Quote bq1("444-555-666", 20.0, 5, 0.1); // Bulk_Quote: constructor taking string, double, size_t and double
            Bulk_Quote bq2; // Bulk_Quote: constructor
            bq2 = std::move(bq1); // Bulk_Quote: std::move assignment operator
            cout << "Destroying the Bulk_Quote objects..." << endl;
            break;
        }

        case 11: // Creating a vector of Quote objects
        {
            cout << "Creating a vector of Quote objects..." << endl;
            vector<Quote> vec;
            vec.push_back(Quote("111-222-333", 20.0)); // Quote: constructor taking string and double
            vec.push_back(Quote("777-888-999", 10.0)); // Quote: constructor taking string and double
            cout << "Destroying the vector of Quote objects..." << endl;
            break;
        }

        case 12: // Creating a vector of Bulk_Quote objects
        {
            cout << "Creating a vector of Bulk_Quote objects..." << endl;
            vector<Bulk_Quote> vec;
            vec.push_back(Bulk_Quote("444-555-666", 20.0, 5, 0.1)); // Bulk_Quote: constructor taking string, double, size_t and double
            vec.push_back(Bulk_Quote("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double
            cout << "Destroying the vector of Bulk_Quote objects..." << endl;
            break;
        }

        case 13: // Creating a vector of Quote pointers
        {
            cout << "Creating a vector of Quote pointers..." << endl;
            vector<Quote*> vec;
            vec.push_back(new Quote("111-222-333", 20.0)); // Quote: constructor taking string and double
            vec.push_back(new Quote("777-888-999", 10.0)); // Quote: constructor taking string and double
            for (auto q : vec)
            {
                delete q;
            }
            cout << "Destroying the vector of Quote pointers..." << endl;
            break;
        }

        case 14: 
        {
            vector<Quote> vec;
            vec.push_back(Quote("111-222-333", 20.0)); // Quote: constructor taking string and double
            vec.push_back(Bulk_Quote("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double
            for (auto q : vec)
            {
                cout << q.isbn() << ": " << q.net_price(5) << endl;
            }

            cout << "Destroying the vector of Quote objects..." << endl;
            break;
        }

        case 15:
        {
            vector<Quote*> vec;
            vec.push_back(new Quote("111-222-333", 20.0)); // Quote: constructor taking string and double
            vec.push_back(new Bulk_Quote("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double
            for (auto q : vec)
            {
                cout << q->isbn() << ": " << q->net_price(5) << endl;
            }
            for (auto q : vec)
            {
                delete q;
            }

            cout << "Destroying the vector of Quote pointers..." << endl;
            break;
        }

        case 16: 
        {
            vector<shared_ptr<Quote>> vec_sp;
            vec_sp.push_back(make_shared<Quote>("111-222-333", 20.0)); // Quote: constructor taking string and double
            vec_sp.push_back(make_shared<Bulk_Quote>("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double
            for (auto sp : vec_sp)
            {
                cout << sp->isbn() << ": " << sp->net_price(5) << endl;
            }
            cout << "Destroying the vector of shared_ptr<Quote>..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid test case number." << endl;
            break;
        }
    }
    return;
}


int main() {
    int testcase;
    cout << "Enter the test case number (1-16): ";
    cin >> testcase;

    TestCaseForE1526(testcase);

    return 0;
}
