function [vect, value] = pop(vect)
    %Check if stack is full
    if isempty(vect)
        fprintf('The stack is underflowing.\n');
        value = -1;
    else
        value = vect(length(vect));
        vect(length(vect))=[];
    end
end