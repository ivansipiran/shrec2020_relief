function hks = Eigen2HKS2(evecs, evals, A)
scale = true;
tmin = abs(4*log(10) / evals(end));
tmax = abs(4*log(10) / evals(2));
nstep = 100;

stepsize = (log(tmax) - log(tmin)) / nstep;
logts = log(tmin):stepsize:log(tmax);
ts = exp(logts);

if scale == true, 
   hks = abs( evecs(:, 2:end) ).^2 * exp( ( abs(evals(2)) - abs(evals(2:end)) )  * ts);
   Am = sparse([1:length(A)], [1:length(A)], A);
   colsum = sum(Am*hks);
   scale = 1.0./ colsum; 
   scalem = sparse([1:length(scale)], [1:length(scale)], scale);
   hks = hks * scalem;
else
   hks = abs( evecs(:, 2:end) ).^2 * exp( - abs(evals(2:end)) * ts);
end