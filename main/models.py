from django.db import models


# Create your models here.

# ALWAYS => python manage.py migrate --run-syncdb


class Pomiar(models.Model):
    temperature = models.CharField(max_length=20)
    distance = models.CharField(max_length=20)

    def __str__(self):
        return str(self.id)
