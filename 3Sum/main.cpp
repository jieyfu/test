//
//  main.cpp
//  3Sum
//
//  Created by FuJieying on 10/22/14.
//  Copyright (c) 2014 FuJieying. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    if (num.size() < 3) {
        return result;
    }
    sort(num.begin(), num.end());
    const int target = 0;
    auto last=num.end();
    for (auto a = num.begin(); a < prev(last, 2); ++a) {
        if (*a == *(a - 1)) {
            continue;
        }
        auto b = next(a);
        auto c = prev(last);
        while (b < c) {
            if (*a + *b + *c < target) {
                do{
                    ++b;
                }while(b < c && *b == *(b-1));
            } else if (*a + *b + *c > target) {
                do{
                    --c;
                }while(c > b && *c == *(c+1));
            } else {
                result.push_back({*a, *b, *c});
                do{
                    ++b;
                }while(b < c && *b == *(b-1));
                do{
                    --c;
                }while(c > b && *c == *(c+1));
                
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result = threeSum(num);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << endl;
        }
    }
    std::cout << "Hello, World!\n";
    return 0;
}
