#include <iostream>
#include<algorithm>
using namespace std;

void ReverseString ()
{
    string sent ;
    cout << "Enter a string to reverse it : ";
    getline(cin, sent);

   for (int i = sent.length()-1 ; i >=0 ; i--)
   {
    cout << sent[i] << " ";
   }
//    reverse(sent.begin(), sent.end());
//    cout << sent ;    (direct method)
}

int MissingNumber(int arr[], int n)
{
   int num = n+1;
   int actualSum = 0;
   int TotalSum = num * (num + 1)/2;
   for (int i = 0; i < n; i++)
    actualSum += arr[i];
   return TotalSum - actualSum;
}
bool PalindromeChecker (string sentence)
{
    string palindrome = sentence;
    reverse(palindrome.begin(), palindrome.end());
    return (palindrome == sentence);
}

int main()
{
    ReverseString();
    //------------------------------
      int arr[] {2,4,8,10};
      int size = sizeof(arr)/sizeof(arr[0]);
      int ans = MissingNumber(arr,size);
      cout << "Missing number : " << ans;
    //--------------------------------
    string sen;
    cout << "Enter a string to check if it's a palindrome or not : ";
    getline(cin, sen);
    for (int i = 0; i < sen.length(); i++)
    {
         sen[i] = tolower(sen[i]);
    }
    if (PalindromeChecker(sen))
      cout << "Match found!(uppercase letters are converted to lower case)";
    else
      cout << "Noo match found!";
    return 0;
}