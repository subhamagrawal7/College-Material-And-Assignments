function [even_count, odd_count] = even_odd(z)
even_count = 0;
odd_count = 0;
for i = 1:length(z)
    if mod(z(i),2) == 0
        even_count = even_count + 1;
    else 
        odd_count = odd_count + 1;
    end
end
end