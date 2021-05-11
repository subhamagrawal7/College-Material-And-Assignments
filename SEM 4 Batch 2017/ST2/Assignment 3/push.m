function vect = push(vect, value,n)
    %Check if stack is full
    if length(vect) == n
        fprintf('The stack is overflowing.\n');
    else
        vect(length(vect) + 1) = value;
    end
end