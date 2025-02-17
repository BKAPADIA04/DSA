class Solution {
public:
    pair<double,double> area(vector<vector<int>>& squares,double mid) {
        double area1 = 0.0;
        double area2 = 0.0;
        // cout << "mid : " << mid << endl;

        for(int i = 0;i < squares.size();i++) {
            int y1 = squares[i][1] + squares[i][2]; 
            int y2 = squares[i][1];

            // cout << mid << " " << y1 << " " << y2 << endl;

            if(mid >= y1) {
                area1 += ((double)squares[i][2] * (double)squares[i][2] * 1.0);
            }
            else if(mid <= y2) {
                area2 += ((double)squares[i][2] * (double)squares[i][2] * 1.0);
            }
            else {
                double height1 = (mid - squares[i][1]) * 1.0;
                double height2 = (squares[i][2] - height1) * 1.0;
                area1 += squares[i][2] * height1 * 1.0;
                area2 += squares[i][2] * height2 * 1.0;
            }
            // cout << area1 << " " << area2 << endl;
        }
        return {area1,area2};
    }

    double separateSquares(vector<vector<int>>& squares) {
        double high = 0.0; double low = 1e9;
        for(int i = 0;i < squares.size();i++) {
            high = max(high,(squares[i][1] + squares[i][2])*1.0);
            low = min(low,squares[i][1]*1.0);
        }
        double ans = 0.0;
        double precision = 1e-5;
        while(high - low > precision) {
            double mid = (low + high)/2.0;
            pair<double,double>a = area(squares,mid);
            
            if(a.first >= a.second) {
                ans = mid;
                high = mid;
            }
            else {
                // ans = mid;
                low = mid;
            }
        }
        return ans;
    }
};
