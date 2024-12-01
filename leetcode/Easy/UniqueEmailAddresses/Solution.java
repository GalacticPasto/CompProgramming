package UniqueEmailAddresses;
import java.util.HashSet;
public class Solution {
    public static void main(String[] args){
        String[] emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
        System.out.println(numUniqueEmails(emails));
    } 
    private static int numUniqueEmails(String[] emails){
        HashSet<String> set = new HashSet<>();
        for(String s : emails){
            int atPos = s.indexOf("@");
            String localName = s.substring(0, atPos);
            String domainName = s.substring(atPos + 1 , s.length());
            if (localName.contains("+")) {
                int plusPos = localName.indexOf("+");
                localName = localName.substring(0, plusPos);
            }
            localName = localName.replaceAll("\\." , "");
            String newName = localName + domainName;
            set.add(newName);
        }
        return set.size();
    }
}
