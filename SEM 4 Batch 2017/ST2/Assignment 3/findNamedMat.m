function [x_ind, y_ind] = findNamedMat(mat, reqName)
   for i = 1:2
       vect = mat(i,:);
       [tf, idx] = ismember(reqName, vect);
       if tf 
           x_ind = i;
           y_ind = idx;
           break;
       else
           x_ind = -1;
           y_ind = -1;
       end
   end
end