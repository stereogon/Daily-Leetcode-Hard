class MedianFinder
{
public:
  priority_queue<int> pqstart; // maxheap : smallest elements
  priority_queue<int, vector<int>, greater<int>>
      pqend; // minheap : largest elementss
  int sz = 0;

  MedianFinder() {}

  void addNum(int num)
  {
    sz += 1;

    if (pqstart.size() == 0 && pqend.size() == 0)
    {
      pqstart.push(num);
    }
    else
    {
      if (num < pqstart.top())
      {
        pqstart.push(num);
      }
      else
      {
        pqend.push(num);
      }
    }

    while (abs((int)pqstart.size() - (int)pqend.size()) > 1)
    {
      if (pqstart.size() > pqend.size())
      {
        int num = pqstart.top();
        pqstart.pop();
        pqend.push(num);
      }
      else
      {
        int num = pqend.top();
        pqend.pop();
        pqstart.push(num);
      }
    }
  }

  double findMedian()
  {
    if (sz % 2)
    {
      if (pqstart.size() > pqend.size())
      {
        return pqstart.top();
      }
      else
      {
        return pqend.top();
      }
    }
    else
    {
      return (pqstart.top() + pqend.top()) / (double)2;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */