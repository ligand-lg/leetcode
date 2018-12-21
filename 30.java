import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
 public List<Integer> findSubstring(String s, String[] words) {
  ArrayList<Integer> al = new ArrayList<Integer>();
  
  if (s.length() == 0 || words.length == 0)
   return al;
  int len = words.length;
  int sumlen = len * words[0].length();
  HashMap<String, Integer> hm = new HashMap<String, Integer>();
  for (int i = 0; i < words.length; i++) {
   if (hm.get(words[i]) == null) {
    hm.put(words[i], 1);
   } else {
    hm.put(words[i], hm.get(words[i]) + 1);
   }
  }

  for (int i = 0; i < s.length(); i++) {
   if (i + sumlen > s.length())
    continue;
   HashMap<String, Integer> _hm = new HashMap<String, Integer>();
   for (int j = 0; j < words.length; j++) {
    _hm.put(words[j], hm.get(words[j]));
   }
   boolean flag = true;

   for (int j = i; j < i + sumlen; j += words[0].length()) {

    String now = s.substring(j, j + words[0].length());

    if (_hm.get(now) == null || _hm.get(now) == 0) {
     flag = false;
     break;
    }

    _hm.put(now, _hm.get(now) - 1);
   }
   if (flag) {
    al.add(i);
   }
  }

  return al;

 }

 public static void main(String[] args) {

 }
}