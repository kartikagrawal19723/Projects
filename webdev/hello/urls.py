from django.urls import path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("kartik", views.kartik, name="kartik"),
    path("<str:name>", views.greet, name="greet")
]
