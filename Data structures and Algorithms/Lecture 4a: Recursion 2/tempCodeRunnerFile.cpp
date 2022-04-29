    outputIndex = 0; // Make sure that the index for the output array starts from 0 while for the input index starts from startIndex
    for (int index = startIndex; index <= endIndex; ++index)
    {
        input[index] = output[outputIndex++];
    }
}