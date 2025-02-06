for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
    for (int secondIndex = firstIndex + 1; secondIndex < numsLength; secondIndex++) {
        // Add the number of tuples for this product to the total (each pair
        // can form 8 tuples)
        totalNumberOfTuples += 8 * pairProductsFrequency[nums[firstIndex] * nums[secondIndex]];
        
        // Increment the frequency of the product of the current pair
        pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
    }
}

return totalNumberOfTuples;