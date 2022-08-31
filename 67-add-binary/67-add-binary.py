class Solution(object):
    def decimalToBinary(self,n):
        return bin(n).replace("0b","")
    def binaryToDecimal(self,n):
        return int(n,2)
        
    def addBinary(self, a, b):
        c = self.binaryToDecimal(a)
        d = self.binaryToDecimal(b)
        
        ans = c + d
        return self.decimalToBinary(ans)
        