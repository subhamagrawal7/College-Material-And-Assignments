function resultVect = passOrFail(marksVect)
    for i = 1:length(marksVect)
       if marksVect(i) > 30
          resultVect(i) = 1;
       else
          resultVect(i) = 0;
       end
    end
end