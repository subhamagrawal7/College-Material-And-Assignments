angular.module('myApp', []).controller('personCtrl', function($scope) {
    $scope.firstName = "Hardi",
    $scope.lastName = "Desai",
    $scope.fullName = function() {
        return $scope.firstName + " " + $scope.lastName;
    }
});
