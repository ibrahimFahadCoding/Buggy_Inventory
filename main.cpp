#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int main() {
    using std::cout, std::cin, std::setw, std::left, std::right;

    cout << "Today's shipments:\n\n";
    cout << "| " << left << setw(20) << "Truck Type" << " | " << setw(12) << "Cost" << " | " << setw(12) << "Net Wt." << " |\n";

    // Property of Kant C. Bugg.
    constexpr const char* test_shipment_type1 = "Dairy"; // copy-initialization
    constexpr unsigned long test_shipment_cost1 = 3'145'65UL; // now it can actually store the number
    constexpr double test_shipment_net_wt1 = 12'338.546; // now you get accuracy
    cout << "| " << left << setw(20) << test_shipment_type1 << " | "
         << right << setw(12) << test_shipment_cost1 / 100.0 << " | "
         << right << setw(12) << test_shipment_net_wt1 << " |\n";

    // Property of Kant B. Bugg.
    constexpr const char* test_shipment_type2 = "Grocery"; // list-initialization
    constexpr unsigned long test_shipment_cost2 = 9'983'47UL;
    constexpr double test_shipment_net_wt2 = 15'512.687;
    cout << "| " << left << setw(20) << test_shipment_type2 << " | "
         << right << setw(12) << test_shipment_cost2 / 100.0 << " | "
         << right << setw(12) << test_shipment_net_wt2 << " |\n";
    // Property of Kant D. Bugg.
    /*
        ----- RUN ONE -----
    Enter the shipment type: GM
    Enter the shipment origin: Tokyo
    Enter the shipment destination: Paris
    Enter the total cost for the shipment: $30,452.34
    Enter the total weight for the shipment: Enter the shipment distance: 
    GM shipment: Tokyo -> Paris
    $0 | 6.9516e-310lbs. | 0mi.

    ----- RUN TWO -----
    Enter the shipment type: GM
    Enter the shipment origin: Tokyo
    Enter the shipment destination: Paris
    Enter the total cost for the shipment: 34256.34
    Enter the total weight for the shipment: Enter the shipment distance: 3429

    GM shipment: Tokyo -> Paris
    $34256 | 0.34lbs. | 3429mi.

    ----- RUN THREE -----
    Enter the shipment type: General merchandise
    Enter the shipment origin: Enter the shipment destination: Paris
    Enter the total cost for the shipment: 30425.34
    Enter the total weight for the shipment: Enter the shipment distance: 234567

    General shipment: merchandise -> Paris
    $30425 | 0.34lbs. | 234567mi.
    default initalization does nothing in primitives.
    */
    double total_weight; //default initialization (declare var like this: type + name;)
    int total_cost; 
    int total_distance{}; // zero initialization (makes it 0)
    std::string input; //default initialization for non-primitives calls default constructor.
    std::string output; // Strings read anything except whitespace, but integers only read integers.
    cout << "Enter the shipment type: ";
    
    getline(cin,input);
    output += input + " shipment: ";
    cout << "Enter the shipment origin: ";
    
    getline(cin,input);
    output += input + " -> ";
    cout << "Enter the shipment destination: ";
    
    getline(cin,input);
    output += input;
    cout << "Enter the total cost for the shipment (cents): ";
    cin >> total_cost; // when cin fails it zeroes out first variable.
    cin.clear(); //clears error flag
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//ignores bad input
    cout << "Enter the total weight for the shipment: ";
    cin >> total_weight; 
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "Enter the shipment distance: ";
    cin >> total_distance;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "\n" << output << "\n$" << total_cost/100.0 << " | " << total_weight << "lbs. | " << total_distance << "mi.\n";
    return EXIT_SUCCESS;
   
}














