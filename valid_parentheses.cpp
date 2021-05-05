/******************************************************************************
 * Given a string containing just the characters '(', ')', '{', '}', '[', ']', 
 * determine if the input string is valid. An input string is valid if:
 *   open brackets must be closed by the same type of brackets.
 *   open brackets must be closed in the correct order.
 * ***************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;



bool IsValid1(string str)  // '(' and ')' only
{
	if ( str.size() == 0 )  return true;
	if ( str.size() % 2 == 1 )  return false;
	
	int left_count = 0;
	for ( uint32_t i = 0; i < str.size(); ++i )
	{
		if ( str[i] == '(' )  ++left_count;
		if ( str[i] == ')' )  if ( --left_count < 0 )  break;
	}
	return left_count == 0;
}



bool IsValid2(string str)  // '(', ')', '{', '}', '[', ']' 
{
	unordered_map<char, char> parentheses { {'(', ')'}, {'[', ']'}, {'{', '}'} }; 
	stack<char> st;

	for ( uint16_t i = 0; i < str.size(); ++i )
	{
		char ch = str[i];
		
		if ( parentheses.count(ch) == 1 )  // If the current character is an opening bracket
			st.push(ch);
		
		else  // If the current character is a closing bracket
		{
			if ( st.empty() )  return false;
			if ( parentheses[st.top()] != ch )  return false;
			st.pop();
		}
	}
	return st.empty();	
}



int main()
{
	cout << boolalpha;
	
	cout << IsValid1("") << '\n';
	assert( IsValid1("") == true );

	cout << IsValid1("(") << '\n';
	assert( IsValid1("(") == false );

	cout << IsValid1("()") << '\n';
	assert( IsValid1("()") == true );
	
	cout << IsValid1("(()))") << '\n';
	assert( IsValid1("(()))") == false );
	
	cout << IsValid1("(()()())") << '\n';
	assert( IsValid1("(()()())") == true );
	
	cout << IsValid1("(()))(") << '\n';
	assert( IsValid1("(()))(") == false );
	
	cout << IsValid1("(((())))()(())") << '\n';
	assert( IsValid1("(((())))()(())") == true );
	
	
	cout << '\n' << IsValid2("[") << '\n';
	assert( IsValid2("[") == false );
	
	cout << IsValid2("()[]{}") << '\n';
	assert( IsValid2("()[]{}") == true );
	
	cout << IsValid2("([)]") << '\n';
	assert( IsValid2("([)]") == false );
	
	cout << IsValid2("{[()][()]}") << '\n';
	assert( IsValid2("{[()][()]}") == true );
}
