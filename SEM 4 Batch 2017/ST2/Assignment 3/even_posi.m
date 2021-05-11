function res = even_posi(z)
k = 1;
for i = 2:2:length(z)
    res(k) = z(i);
    k = k + 1;
end
end