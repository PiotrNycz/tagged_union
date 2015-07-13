# tagged_union
Contains:<BR><UL>
  <LI>tagged_union: like boost::variant but accessed by tag - tag can be enum value, 
  <pre><code>
  enum discriminator { name, number, dimensions };
  exp::tagged_union&lt;discriminator&gt;
            ::with&lt;name&gt;::as&lt;std::string&gt;
            ::with&lt;number&gt;::as&lt;int&gt;
            ::with&lt;dimensions&gt;::as&lt;std::vector&lt;int&gt;&gt;::type a, b;
  </code></pre>
  <LI>unrestricted_union: implementation of C++11 unrestricted union - like std::tuple to simple struct
  <pre><code>
  exp::unrestricted_union&lt;std::string,int,std::vector&lt;int&gt;&gt; a, b;
  </code></pre>
  <LI>indexed_union: like boost::variant but based on C++11 unrestricted union
  <pre><code>
  exp::indexed_union&lt;std::string,int,std::vector&lt;int&gt;&gt; a, b;
  </code></pre>

TODO:<BR><UL>
   <LI>tagged_tuple
   <LI>tagged_array
   <LI>optional - based on tagged_union tagged with bool:true and bool:false
   
  
