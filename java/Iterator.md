## Iterator
``` java
import java.util.*;
public class Main
{
public static void main(String[] args)
{
reverseList<String> rlist  = new reverseList<>();
rlist.add("a");
for(String s:rlist)
System.out.println(s);
}
}

class reverseList<T> implements Iterable<T>
{
private List<T> list = new ArrayList<>();
public void add(T t)
{
list.add(t);
}
@Override
public Iterator<T> iterator()
{
return new reverseIterator(list.size());
}
class reverseIterator implements Iterator<T>
{
int index;
reverseIterator(int index)
{
this.index=index;
}
@Override
public boolean hasNext()
{
return index>0;
}
@Override
public T next()
{
index--;
return reverseList.this.list.get(index);
}
}
}
```