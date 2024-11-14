class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int size = quantities.size();
        int lowX = 1, highX = quantities[size - 1];

        int minX = highX;
        while (lowX <= highX) {
            int midX = (lowX + highX) / 2;

            int storesUsed = 0;
            for(auto quantity : quantities) {
                storesUsed += ceil(static_cast<double>(quantity) / midX);
            }

            if(storesUsed <= n) {
                minX = midX;
                highX = midX - 1;
            } else {
                lowX = midX + 1;
            }
        }
        return minX;

        /*
        n specialty retail stores
        quantities[i] = product types

        1 Store
        <= 1 product type (any amount of quantity)

        After Distribution,
        Store 1 -> 1 product type with say 10 quantity
        Store 2 -> 1 product type with say 20 quantity
        Store 3 -> 0 product type with say 0 quanity

        X is 20 since the max quantity is 20
        X should be small as possible

        Inferences:
        * Distribute more in equal proportions to reduce higher 
        for any one store
        * Distribute a product type with higher quantity to multiple
        stores
        
        return the minimum possible x



        */
    }
};