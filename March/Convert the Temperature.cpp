I Approach (Brute-Force Method)

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin=celsius+273.15;
        double fahrenheit=celsius * 1.80 + 32.00;

        return {kelvin,fahrenheit};
    }
};

Time Complexity=O(1).
Space Complexity=O(1).