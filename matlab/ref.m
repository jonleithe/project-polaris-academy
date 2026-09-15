function U = ref(A)

    [m,n] = size(A);
    row = 1;

    for col = 1:n

        % Find a pivot
        pivot = find(A(row:m,col) ~= 0, 1);

        if isempty(pivot)
            continue
        end

        pivot = pivot + row - 1;

        % Swap pivot row into position
        if pivot ~= row
            A([row pivot],:) = A([pivot row],:);
        end

        % Eliminate entries below pivot
        for r = row+1:m
            factor = A(r,col) / A(row,col);
            A(r,:) = A(r,:) - factor*A(row,:);
        end

        row = row + 1;

        if row > m
            break
        end
    end

    U = A;
end