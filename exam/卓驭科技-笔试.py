
# [1,8,6,2,5,4,8,3,7]

input_=input()
# input_="[1,8,6,2,5,4,8,3,7]"
nums=[int(i) for i in input_[1:-1].split(',')]

left=0
right=len(nums)-1

max_cap=0

while left<right:
    # 容量取决于短板
    if nums[left]>nums[right]:
        cap=nums[right]*(right-left)
        right-=1
    else:
        cap=nums[left]*(right-left)
        left+=1
    if cap>max_cap:
        max_cap=cap
    
    
print(max_cap)