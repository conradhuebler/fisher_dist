# fisher_dist
fisher's distribution for f-test

Simple header only tool to calculate the x quantile of the fisher distribution for given m and n degrees of freedom.

# Usage
## Download and installation
Download from githib via
git clone git@github.com:contra98/fisher_dist.git

and include fisher_dist.h in your project

## Function

finv(x, m, n)

x - quantile
m, n - degrees of freedom
m and n should each be lower than 250 and in sum lower than 256. If they are greater, they will be altered to the highest allowed value, the result will then differ in the third decimal place.
