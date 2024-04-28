import datetime

from sqlalchemy import Column, Integer, String, Boolean, Float, Text, ForeignKey, Date, DateTime, func

from sqlalchemy.orm import relationship

from db import Base


class Parametrs(Base):
    __tablename__ = "Parametrs"
    id = Column(Integer, primary_key=True, autoincrement=True)
    temperatura = Column(Float,nullable=True)
    wet = Column(Float,nullable=True)
    natural_gas = Column(Float,nullable=True)
    gas = Column(Float,nullable=True)
    dust1 = Column(Float,nullable=True)
    dust2 = Column(Float,nullable=True)
    dust3 = Column(Float,nullable=True)
    lux = Column(Float,nullable=True)
    date = Column(Date(), nullable=True, default=func.now())
    status = Column(Boolean, nullable=True, default=True)



