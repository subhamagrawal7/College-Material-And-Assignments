function fact = sfactorial(n)
    if n < 0
        fprintf('Error : The number is negative..\n');
        fact = -1;
    elseif mod(n,1) ~= 0
        fprintf('Error: The number is not an integer.');
        fact = -1;
    else
        if n == 0
            fact = 1;
        else
            fact = 1;
            for i = 1:n
                fact = fact * i;
            end
        end
    end
end