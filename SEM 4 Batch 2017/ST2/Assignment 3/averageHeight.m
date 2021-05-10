function avg = averageHeight(vect_height)
    sum = 0;
    for i = 1:length(vect_height)
        sum = sum + vect_height(i);
    end
    avg = sum/length(vect_height);
end