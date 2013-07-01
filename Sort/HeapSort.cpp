//-----------------------------------------------------------------------------
template <typename T>
void _AdjustDownwards(T *l, int size, int current)
{
    while(current < size)
    {
        int max;
        
        if(2*current + 2 < size)
            max = l[2*current+1] > l[2*current + 2] ? 2*current+1:2*current+2;
        else if(2*current + 1 < size)
            max = 2*current + 1;
        else
            break;

        if(l[current] < l[max])
        {
            std::swap(l[current], l[max]);
            current = max;
        }
        else
        {
            break;
        }
    }
    return;
}
//-----------------------------------------------------------------------------
template <typename T>
void HeapSort(T *l, int size)
{
    //adjust upwards O(n)
    for(int i = size/2-1; i >=0; --i)
    {
        _AdjustDownwards(l, size, i);
    }
    
    //calc O(nlgn)
    for(int i=0; i<size-1; ++i)
    {
        std::swap(l[0], l[size-i-1]);
        _AdjustDownwards(l, size-i-1, 0);
    }
}
