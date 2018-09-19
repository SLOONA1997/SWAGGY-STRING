#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

void removeDuplicates(char *str)
{	
    if (!str)
        return;    
    int len = strlen(str);
    if (len < 2)	
        return;
	
    int tail = 1;	
    for (int i = 1; i < len; ++i)
    {		
        int j;		
        for (j = 0; j < tail; ++j)			
            if (str[i] == str[j])				
                break;
		
        if (j == tail) 
        {			
            str[tail] = str[i];
            ++tail;
        }	
    }	
    str[tail] = '\0';
}

void subsequence(char s[], char t[], int n, int k,char temp[])
{
	int last = 0, cnt = 0, new_last = 0, size = 0;

	// Starting from largest charter 'z' to 'a'
	for (int ch = strlen(temp); ch >= 0; ch--) {
		cnt = 0;

		// Counting the frequency of the character
		for (int i = last; i < n; i++) {
			if (s[i] == temp[ch])
				cnt++;
		}

		// If frequency is greater than k
		if (cnt >= k) {

			// From the last point we leave
			for (int i = last; i < n; i++) {

				// check if string contain ch
				if (s[i] == temp[ch]) {

					// If yes, append to output string
					t[size++] = temp[ch];
					new_last = i;
				}
			}

			// Update the last point.
			last = new_last;
		}
	}
	t[size] = '\0';
}





int main() {
    char s[]="vtgctgctgctg";
    char temp[strlen(s)+1];
    strcpy(temp,s);
    removeDuplicates(temp);
    
    sort(temp,temp+strlen(temp));

   int n = sizeof(s);
	int k = 2;
	char t[n];
	subsequence(s, t, n - 1, k,temp);
	cout << t << endl;
    return 0;
}
