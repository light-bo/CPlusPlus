//求解n个元素的所有的子集的递归解法
template <typename T>
void enum_sub(const T collect[], size_t num, vector<T> v){
     if(num <= 0){
          cout<<"{";
          for(auto iter=v.begin();iter!=v.end();++iter){
               //格式化输出
               cout<<*iter<<(((iter+1) == v.end())?"":", ");
          }
          cout<<"}"<<endl;
          return;
     }

     //递归列出子集
     enum_sub(collect+1, num-1, v);
     v.push_back(collect[0]);
     enum_sub(collect+1, num-1, v);
}

