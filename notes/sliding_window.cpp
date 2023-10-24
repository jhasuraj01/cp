template <typename T>
T sliding_window(vector<T> &nums) {
  int n = nums.size();
  int start = 0;
  int end = 0;

  T curr_value;
  T final_value;
  
  while(start < n) {
      if(end < n && /* condition for inclusion */) {
          // add element at `end` to curr_value
          end++;
      }
      else {
          // remove element at `start` from curr_value
          start++;
      }
      int curr_len = end - start;
      // update `final_value` using `curr_value`
  }

  return final_value;
}
