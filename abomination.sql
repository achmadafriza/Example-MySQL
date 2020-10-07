SELECT Orders.OrderDate, Orders.OrderID, Products.ProductName, Products.Price, OrderDetails.Quantity, SUM(Products.Price * OrderDetails.Quantity) AS TotalPrice, (
SELECT SupplierName
FROM Suppliers
WHERE Products.SupplierID = SupplierID
) AS Supplier

FROM OrderDetails
INNER JOIN Products ON OrderDetails.ProductID = Products.ProductID
INNER JOIN Orders ON OrderDetails.OrderID = Orders.OrderID

GROUP BY OrderDetails.OrderID
HAVING Orders.OrderDate LIKE '1997%' AND SUM(Products.Price * OrderDetails.Quantity) >= (
SELECT AVG(Products.Price * OrderDetails.Quantity)
FROM OrderDetails
INNER JOIN Products ON OrderDetails.ProductID = Products.ProductID
)