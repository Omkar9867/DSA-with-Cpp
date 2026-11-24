#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin >> s;

    long long have_B, have_S, have_C;
    std::cin >> have_B >> have_S >> have_C;

    long long price_B, price_S, price_C;
    std::cin >> price_B >> price_S >> price_C;

    long long money;
    std::cin >> money;
    //-------------------------------TC->O(logn)--SC->O(1)----------------------------------
    long long count_of_B = 0;
    long long count_of_S = 0;
    long long count_of_C = 0;

    for (long long i = 0; i < s.size(); i++){ // For Reciepe
        if (s[i] == 'B'){
            count_of_B++;
        }else if (s[i] == 'S'){
            count_of_S++;
        }else{
            count_of_C++;
        }
    }

    long long low = 0;
    // Upper bound reasoning: money <= 10^12 and the cheapest ingredient costs
    long long high = 1e13;
    long long ans;

    while (low <= high){
        long long mid = (low + high) / 2;

        long long money_needed = 0;

        // For each ingredient: mid burgers need mid*count units, of which the
        // stock covers some. max(0, ...) clamps the surplus case — having more
        // than needed costs nothing, it doesn't refund into the budget.// Meaning to avoid negative price which should be handled at 0;
        money_needed += std::max(0LL, mid * count_of_B - have_B) * price_B;
        money_needed += std::max(0LL, mid * count_of_S - have_S) * price_S;
        money_needed += std::max(0LL, mid * count_of_C - have_C) * price_C;

        if (money_needed <= money){
            ans = mid;
            low = mid + 1; // We can go higer
        }else{
            high = mid - 1; // We should go down
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// Time Complexity: O(log2(SS)) = O(10^13) ~ O(43)
// Space Complexity: O(1)

/*
    C. Hamburgers

    Time Limit: 1 second
    Memory Limit: 256 megabytes

    Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) and 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.

    Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.

    Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

    Input

    The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).

    The second line contains three integers nb, ns, nc (1 <= nb, ns, nc <= 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen.

    The third line contains three integers pb, ps, pc (1 <= pb, ps, pc <= 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 <= r <= 10^12) — the number of rubles Polycarpus has.

    Please, do not write the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, std:: streams or the %I64d std::specifier.

    Output

    Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

    Examples

    Input:
    BBBSSC
    6 4 1
    1 2 3
    4

    Output:
    2

    Input:
    BBC
    1 10 1
    1 10 1
    21

    Output:
    7

    Input:
    BSC
    1 1 1
    1 1 3
    1000000000000

    Output:
    200000000001
*/