var app = angular.module('onscope', []);

    app.controller('FirstCtrl', function($rootScope, $scope){
    	$scope.register = function(){
    		$rootScope.$broadcast('BOOM!', $scope.name)
    	}
    });

    app.controller('SecondCtrl', function($scope){
      $scope.$on('BOOM!', function(events, args){
        console.log(args);
        $scope.name = args;
      })
    });
