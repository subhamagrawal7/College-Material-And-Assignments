function [m_vect, cm_vect] = returnHeight(z, n)
    for i = 1:n
        cm_vect(i) = (100*z(i,1)) + z(i,2);
        m_vect(i) = z(i,1) + (z(i,2)/100);
    end
end

