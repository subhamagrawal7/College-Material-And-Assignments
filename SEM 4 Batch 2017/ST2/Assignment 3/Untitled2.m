function [even, odd] = Untitled2(arr)
    even = 0;
    odd = 0;
    for i = 1:length(arr)
       if mod(arr(i),2) == 0
           even = even + 1;
       else 
           odd = odd + 1;
       end
    end
end