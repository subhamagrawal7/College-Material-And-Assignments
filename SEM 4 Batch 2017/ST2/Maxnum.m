function max = Maxnum(vect)
    for i = 1:length(vect)
       if i == 1
           max = vect(i);
       else
           if vect(i) > max
               max = vect(i);
           end
       end
    end
end