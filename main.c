#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


long long convertToDecimal(const char *value, int base) {
    long long result = 0;
    int length = strlen(value);
    for (int i = 0; i < length; i++) {
        char digit = value[i];
        int numericValue = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'a' + 10;
        result = result * base + numericValue;
    }
    return result;
}


double lagrangeInterpolation(int x[], long long y[], int k) {
    double result = 0.0;

    for (int i = 0; i < k; i++) {
        double term = y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - x[j]) / (x[i] - x[j]); // Lagrange basis polynomial
            }
        }
        result += term;
    }
    return result;
}

int main() {

    int n1 = 4, k1 = 3;
    const char *testcase1_values[] = {"4", "111", "12", "213"};
    int testcase1_bases[] = {10, 2, 10, 4};
    int testcase1_x[] = {1, 2, 3, 6};


    long long y1[n1];
    for (int i = 0; i < n1; i++) {
        y1[i] = convertToDecimal(testcase1_values[i], testcase1_bases[i]);
    }

    double c1 = lagrangeInterpolation(testcase1_x, y1, k1);


    int n2 = 10, k2 = 7;
    const char *testcase2_values[] = {
        "13444211440455345511", "aed7015a346d63", "6aeeb69631c227c", 
        "e1b5e05623d881f", "316034514573652620673", 
        "2122212201122002221120200210011020220200", 
        "201202211222110001002100211020012011121", 
        "20220554335330240002224253", 
        "4515378832281255483", 
        "1101613130313526312514143"
    };
    int testcase2_bases[] = {6, 15, 15, 16, 8, 3, 3, 6, 12, 7};
    int testcase2_x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  
    long long y2[n2];
    for (int i = 0; i < n2; i++) {
        y2[i] = convertToDecimal(testcase2_values[i], testcase2_bases[i]);
    }


    double c2 = lagrangeInterpolation(testcase2_x, y2, k2);

    printf("Secret for Test Case 1: %.0lf\n", c1);
    printf("Secret for Test Case 2: %.0lf\n", c2);

    return 0;
}
