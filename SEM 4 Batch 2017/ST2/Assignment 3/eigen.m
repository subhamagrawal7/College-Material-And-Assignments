function sumOfEigen = eigen(matrix)
    temp = eig(matrix);
    disp(temp);
    sumOfEigen = 0;
    for i = 1:length(temp)
       sumOfEigen = sumOfEigen + temp(i);
    end
end