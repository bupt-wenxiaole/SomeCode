class Solution:
	def isPalindrome(self, s):
		newS=[i.lower() for i in s if i.isalnum()]
		return newS==newS[::-1]