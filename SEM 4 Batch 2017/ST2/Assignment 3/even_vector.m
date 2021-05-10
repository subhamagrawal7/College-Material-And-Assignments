function res = even_vector(z)
k = 1;
for i = 1:length(z)
    if mod(z(i),2) == 0
        res(k) = z(i);
        k = k + 1; 
    end
end
end
