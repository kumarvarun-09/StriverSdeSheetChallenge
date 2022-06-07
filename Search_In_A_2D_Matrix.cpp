#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & matrix, int m, int n, int target) {
    // Write your code here.
      int l = 0, r = m - 1, mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            int elmt = matrix[mid][0];
            if(elmt > target)
                r = mid - 1;
            else if(elmt < target)
            { 
                if(mid + 1 < matrix.size() && matrix[mid + 1][0] <= target)
                l = mid + 1;
                else 
                    break;
            }
            else
                return true;
        }
        l = 0, r = n - 1;
        while(l <= r)
        {
            int midcol = l + (r - l) / 2;
            int elmt = matrix[mid][midcol];
            if(elmt > target)
                r = midcol - 1;
            else if(elmt < target)
                l = midcol + 1;
            else
                return true;
        }
        return false;
}
