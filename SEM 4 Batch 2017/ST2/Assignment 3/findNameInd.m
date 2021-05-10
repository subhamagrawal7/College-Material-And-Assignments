function index = findNameInd(vect, nameReq)
    [tf, idx] = ismember(nameReq, vect);
    if tf
        index = idx;
    else
        index = -1;
    end
end